#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],b[200005],c[200005],p[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=30;i>=1;i--){
		int s=0;
		queue<int>d;
		for(int j=1;j<=n;j++){
			//cout<<a[j]<<" ";
			if(a[j]>=p[i]&&c[j]==0){
				a[j]-=p[i];
				s++;
			}else d.push(j);
		}//cout<<endl;
		if(s==m){
			break;
		}
		if(s>m){
			while(!d.empty()){
				c[d.front()]++;
				//cout<<d.front()<<" ";
				d.pop();
			}//cout<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			if(ans==0)ans=b[i];
			ans&=b[i];
		}
	}
	cout<<ans;
	return 0;
} 
