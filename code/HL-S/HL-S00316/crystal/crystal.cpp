#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int last;
int const N = 500005;
int a[N];
int cha[N];
int chaa;
int jump[N];
int answer, ans;
void re(int num){
	if(num>=1){
		chaa+=cha[num];
		if(jump[num]!=0&&last>=chaa){
			if(chaa!=0){
				int j = last/chaa;
				if(j>jump[num]){
					ans+=jump[num];
					last=last-(chaa*jump[num]);
					num-=jump[num];
					re(num);
				}
				else if(j<=jump[num]){
					ans+=j;
					last=last-(chaa*j);
					num-=j;
					re(num);
				}
			}
			else{
				ans+=jump[num];
				num-=jump[num];
				re(num);
			}
		}
		else if(last>=chaa){
			last-=chaa;
			ans++;
			num--;
			re(num);
		}
	}
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1; i<=n-1; i++){
		cha[i] = a[i+1]-a[i];
		if(cha[i]==0)
			jump[i] = jump[i-1]+1;
		else jump[i]=0;
	}
	for(int i=2; i<=n; i++){
		if(cha[i+1]==0 && i+1<n && cha[i]==0){
		}
		else{
			last = m;
			chaa=0;
			ans=1;
			re(i-1);
			answer = max(answer, ans);
		}
	}
	cout<<answer<<endl;
	return 0;
}
