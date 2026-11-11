#include<bits/stdc++.h>
using namespace std;

long long g[32];
int l[32]={0};
long long a;
bool b[20099][34]={{0}};
long long n,k;

int an(int y){
	a=-1;
	for(int i=y;i>=0;i--){
		if(g[i]>=k){
			a=i;
			l[i]=1;
			break;
		}
	}
	if(a!=-1){
		for(int i=0;i<n;i++){
			if(b[i][a]==0&&b[i][33]==0){
				b[i][33]=1;
				for(int e=y;e>=0;e--){
					g[e]-=b[i][e];
				}
			}
		}
		an(a-1);
	}
	else{
		long long ans=0;
		for(int i=31;i>=0;i--){
			ans*=2;
			ans+=l[i];
		}
		cout<<ans;
		return 0;
	}
}

int er(long i){
	cin>>a;
	int j=0;
	while(a>0){
		b[i][j]=a%2;
		g[j]+=a%2;
		j++;
		a/=2;
	}
	return 0;
}

int main(){
//	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(long i=0;i<n;i++){
		er(i);
	}
	an(31);
	return 0;
}
