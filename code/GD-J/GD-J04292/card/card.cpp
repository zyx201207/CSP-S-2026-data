#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int f = 0,n,m,v = 0,a[500005],s[500005],cnt[300005];
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int k;
			for(k=0;k<v;k++){
				if(s[k] == a[j]){
					f = 1;
					break;
				}
			}
			if(f == 0){
				s[v] = a[j];
				v++;
			}
			else{
				v = k + 1;
			}
			f = 0;
		}
		for(int j=0;j<v;j++){
			cnt[s[j]]++;
		}
		v = 0;
	}
	for(int i=0;i<m;i++){
		cout << cnt[i+1] << " ";
	}
	return 0;
}
