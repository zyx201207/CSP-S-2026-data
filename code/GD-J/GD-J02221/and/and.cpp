#include <bits/stdc++.h>
using namespace std;
int n,m,max_=0,a[200005];
int cmp(int a,int b){
	return (a&b < b&a);
}
auto dfs(int end , int over , string str_){
	if(str_.length()==end && over==m){
		int x[25],i=1;
		for(int _=1;_<=str_.length();_++){
			if(str_[_-1]=='1'){
				x[i]=a[_];
				i++;
			}
		}
		sort(x+1,x+i,cmp);
		int sum=x[1];
		//cout<<str_<<">>=";
		//cout<<"["<<x[1];
		for(int i=2;i<=m;i++){
			//cout<<","<<x[i];
			sum&=x[i];
		}
		//cout<<"] "<<sum<<" "<<over<<endl;
		if(sum>max_){
			max_=sum;
		}
		return 0;
	}else if(str_.length()==end){
		return 0;
	}
	dfs(end,over+1,(string)(str_+'1'));
	dfs(end,over,(string)(str_+'0'));
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(n,0,"");
		cout<<max_;
		return 0;
	} 
	if(n<=2000){
		if(m==1){
			sort(a+1,a+n+1,cmp);
			cout<<a[n];
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						if((a[i]&a[j])>max_){
							max_=(a[i]&a[j]);
						}
					}
				}
			}
			cout<<max_;
		}else{
			int sum=a[1];
			for(int i=2;i<=n;i++){
				sum&=a[i];
			}
			cout<<sum;
		}
	}else{
		for(int i=1;i<=n;i++){
			int x[n+5],p=1;
			for(int j=1;j<=n;j++){
				if(j!=i){
					x[p]=a[j];
					p++;
				}
			}
			sort(x+1,x+n,cmp);
			int cum=x[1];
			for(int i=2;i<n;i++){
				cum&=x[i];
			}
			if(cum>max_){
				max_=cum;
			}
		}
		cout<<max_;
	}
	return 0;
} 
