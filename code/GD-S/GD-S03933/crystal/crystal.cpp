#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],num=1,ljh=0;
long long x[100005],y[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		if(n==1){
			cout<<1;
			return 0;
		}
		else if(n==2){
			if(a[i+1]-a[i]>=0&&a[i+1]-a[i]<=m){		
				cout<<2;
				return 0;
			}
			else if(a[i]-a[i+1]>=0&&a[i]-a[i+1]<=m){
				cout<<2;
				return 0;
			}
		}
		else if(a[i]==a[i+1]+1){
			for(int j=n/2+1;j>=1;j++){
				if(m>2*num+ljh){
					ljh+=2*num;
					num++;
					continue;
				}
				else{
					cout<<2*num+1;
				}
			}
		
		}
		
			
	}
		
	
	
	//for(int i=1;i<=n;i++){
	//	cout<<"a"<<i<<"="<<" "<<a[i]<<endl;
	//}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
