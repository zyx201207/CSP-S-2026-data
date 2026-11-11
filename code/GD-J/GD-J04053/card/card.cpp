#include <bits/stdc++.h>
using namespace std;
int arr[500100],f[300100],cnt[300100],c[500100];
int n,m;

struct xy{
	int r=0,l=0;
}s[300100];
void cover(){
	for (int i=1;i<n;i++){
		if (f[arr[i]] == 0) {
			f[arr[i]]=1;
			s[arr[i]].l=i;
			
		}
		else {
			s[arr[i]].r=i;
			for (int j=i-1 ;j>=s[arr[i]].l;j--){
				c[j]+=1;
	
			}
		}
	}
}

int main (){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> arr[i];
	}
	cover();
	//for (int i=1;i<=n;i++) cout << c[i] << " ";
	//cout << endl;
	for (int i=n;i>=1;i--){
		cnt[arr[i]] += i-c[i]; 
	}
	for (int i=1;i<=m;i++){
		cout << cnt[i] << " " ;
	}
	return 0;
} 
