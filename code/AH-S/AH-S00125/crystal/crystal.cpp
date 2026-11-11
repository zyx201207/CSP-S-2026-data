#include<bits/stdc++.h>
using namespace std;
int n;long long m,a[514154],b[514514],c[514514];
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	//int u=1;
	sort(a+1,a+n+1);
	if(n<=9000){int as=1;long long s=0,k=0;
		for(int i=2;i<=n;i++){
			s=0,k=0;
			for(int j=i;j>=1;j--){
				k+=a[i]-a[j];
				if(k>m)break;
				s++;
			}as=max(as,s);
		}cout<<as;
	}else{
		bool p=false;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){p=true;break;}
		}
		if(p){int u=0;
			for(int i=2;i<=n;i++){
				b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
				if(b[i]>m)break;
				u++;
			}cout<<u;
		}else{
			int o=a[2]-a[1],u=0,v=0;
			for(int i=1;i<=n;i++){
				v+=o*i;if(v>m)break;
				u++;
			}cout<<u;
		}
    }
	return 0;
}
