#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],cnt[500005];
long long desk[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//ios::sync_with_stdin(false);
	//cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int o=i;
		memset(desk,0,sizeof(desk));
	    for(int j=i;j<=n;j++){
			bool b=0;
			int k;
		    for(k=i;k<j;k++){
				//cout << k << ' ' << j << ' ' << a[k] << ' ' << a[j] << endl;
				if(desk[k]==a[j]){
					b=1;
					break;
				}
			}
			if(b){
				for(int l=k+1;l<=j;l++){
					desk[l]=0;
					//cout << j << " " << k << "       ";
				}
				o=k;
			}
			desk[o]=a[j];
			o++;
		}
		for(int j=1;j<=n;j++){
			cnt[desk[j]]++;
			//cout << desk[j] << ' ';
		}
		//cout << endl;
	}
	for(int i=1;i<=m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}