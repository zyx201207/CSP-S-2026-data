//GZ-J00314   陈彧山 	遵义市新蒲新区滨湖中学
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],t[300005],dl[500005],dlt[300005];
long long z[500005],top,lt[300005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(lt[a[j]] == 0){
				lt[a[j]] == top+1;
			}else{
				top = lt[a[j]]-1;
			}
			z[++top] = a[j];
		}
		for(int j = 1;j<=top;j++){
			t[z[j]]++;
		}
		for(int j = 1;j<=300005;j++){
			lt[j] = 0;
		}
		top = 0;
	}
	for(int i = 1;i<=m;i++){
		cout << t[i] << " ";
	}
	return 0;
}
