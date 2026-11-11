//GZ-J00273 ·®³½Îõ
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int s[N],s2[N],ss[N],sx[N];
int main(){
	freopen("card.out","r",stdin);
	freopen("card.in","w",stdout);
	int n,m;cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sx[j]=0;
			ss[j]=0;
		}
		for(int j=1;j<=n;j++){
			ss[s[j]]++;
			sx[j]=s[j];
			if(ss[s[j]>1]){
				int p=0,flag=1;
				while(p<2){
					if(sx[flag]==s[j]) p++;
					if(p==1) {
						ss[sx[flag]]=0;
						sx[flag]=0;
					}
					flag++;

				}
			}
			ss[s[j]]++;

		}
		for(int j=1;j<=m;j++){
			if(ss[j]>0) s2[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << s2[i] << ' ';
	}
	return 0;
}
