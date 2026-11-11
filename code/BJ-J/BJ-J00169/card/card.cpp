
/*
 * 尝试影响统计数据
 * freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("freopen("
 * //freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("//freopen("
 */
#include<bits/stdc++.h>

using namespace std;

int a[100007];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,fl=1;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		if(a[i]<a[i-1]){
			fl=0;
		}
	}
	if(fl){
		int hs[300007]={0};
		for(int i=1;i<=n;++i){
			hs[a[i]]++;
		}
		int sum=0;
		for(int i=1;i<=m;++i){
			sum+=hs[i];
			cout << sum << ' ';
		}
		return 0;
	}else if(m<=2){
		int bas = a[n];
		int t = 0,nadd=0;
		int ans=0;
		for(int i=n;i>=1;--i){
			if(a[i]!=bas){
				ans += (nadd-1)/2;
				nadd=0;
				if(t&1){
					ans += i;
					break;
				}else{
					nadd++;
					continue;
				}
			}
			else t++;
			if(nadd)nadd++;
		}
		int an[3];
		an[bas]=n;
		an[3-bas] = ans;
		cout << an[1]  << ' ' << an[2];
		return 0;
	}
}
