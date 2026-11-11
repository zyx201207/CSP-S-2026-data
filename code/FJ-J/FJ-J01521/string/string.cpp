#include<bits/stdc++.H>
using namespace std;

string s;
int n,ans = 0;

int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		int a;
		string c;
		cin >> a >> c;
		while(a--){
			s+=c;
		}
	}
	cout << s;
	int i = 0;
	int l = s.size();
	while(true){
		if(i >= l / 2) break;
		if(s[i] != s[l - 1 - i]) ans++;
		i++;
	}
	printf("%d",ans);
	return 0;
}
