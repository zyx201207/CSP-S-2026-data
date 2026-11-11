#include <iostream>
#include <cstring>
using namespace std;

int n,ans;
char str[200005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=0;
	for (int i=1; i<=n; i++) {
		int l;
		char c;
		cin>>l>>c;
		for (int j=1; j<=l; j++) str[t+j-1]=c;
		t+=l;
	}
	int h=0;
	t=strlen(str)-1;
	while (h<t) {
		if (str[h]!=str[t]) ans++;
		h++;
		t--;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
