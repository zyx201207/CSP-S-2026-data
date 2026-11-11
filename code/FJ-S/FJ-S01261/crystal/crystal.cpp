#include<bits/stdc++.h>
using namespace std;
struct st{
	long long v;
	int c;
}b[500005];
long long a[500005],m;
int n,cnt=1,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	b[0].v=a[0],b[0].c=1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			b[cnt-1].c++;
		}else{
			b[cnt++].v=a[i];
			b[cnt-1].c=1;
		}
	}
	for(int i=cnt-1;i>=0;i--){
		int s=b[i].c;
		long long u=m;
		for(int j=i-1;j>=0;j--){
			if(b[i].v-b[j].v<=u){
				if((b[i].v-b[j].v)*b[j].c<=u){
					s+=b[j].c;
					u-=(b[i].v-b[j].v)*b[j].c;
				}else{
					s+=u/(b[i].v-b[j].v);
					u%=b[i].v-b[j].v;
				}
			}else{
				break;
			}
		}
		if(s>ans){
			ans=s;
		}
	}
	cout<<ans;
	return 0;
}
