#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
int n;
ll a[N];
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	
	int i=1,j=n;
	ll res=0;
	while(i<j){
		ll ai=a[i];
		char ci=c[i];
		ll cnt=0ll;
		while(j>i && cnt+a[j]<ai){
			cnt+=a[j];
			if(ci!=c[j]) res+=a[j];
			a[j]=0ll;
			j--;
		}
		if(cnt<ai){
			a[j]-=ai-cnt;
			if(ci!=c[j]) res+=ai-cnt;
		}
		a[i]=0ll;
		i++;
	}
	
	cout << res << "\n";
	return 0;
}
