#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],num=1,ed=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ed=max(ed,a[i]);
	}
	/*for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	while(num*2<=ed) num*=2;
	int j=0,term=0;//j是数组里面储存的数量 
	bool ok=false;
	while(!ok){
		j=0;
		term++;
		//cout<<"term "<<term<<endl;
		if(term%2==1){
			for(int i=0;i<n;i++){
				if((a[i]&num)==num){
					b[j]=a[i];
					j++;
					//cout<<b[j-1]<<" ";
				}
			}
			//cout<<"num="<<num<<endl;
		}else{
			for(int i=0;i<n;i++){
				if((b[i]&num)==num){
					a[j]=b[i];
					j++;
				}
			}
			//cout<<"num="<<num<<endl;
		}
		if(num==1) ok=true;
		if(j>m) n=j;
		if(j<m) term--;
		if(j==m) ok=true;
		num/=2;
	}
	int ans;
	if(term%2==1){
		ans=b[0];
		for(int i=1;i<m;i++){
			ans=ans&b[i];
		}
	}
	else{
		ans=a[0];
		for(int i=1;i<m;i++){
			ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
}

