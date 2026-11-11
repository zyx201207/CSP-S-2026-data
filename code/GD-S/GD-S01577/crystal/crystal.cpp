#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
ll a[N],n,m,sum=1,v[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",a+i);
	}sort(a,a+n);
	for(int i=0;i<n;i++){
		m-=(a[i+1]-a[i])*(i+1);
		if(m<0){
			if((a[i+1]-a[i])<v[v[0]]){
				m+=v[v[0]];
				v[v[0]]=0;
				v[0]--;
			}else{
				break;
			}
		}else{
			sum++;
		}v[++v[0]]=a[i+1]-a[i];
	}printf("%lld",sum);
	return 0;
}
