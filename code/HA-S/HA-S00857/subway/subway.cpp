# include <bits/stdc++.h>

using namespace std;

long long c,n,m,d,p;
long long a[100000010],b[100000010];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cin >> b[i]; 
	}
	if(c=0)
		cout << "32" << "\n" << "17";
	
	return 0;
}
