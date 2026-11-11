#include<bits/stdc++.h>
#define Year2026 ios::sync_with_stdio(0);
#define October cin.tie(0),
#define thirtyone cout.tie(0);
#define fori for(int i = 1; i <= n; i ++)
#define form for(int i = 1; i <= mid; i ++)
#define for_m for(int i = mid + 1; i <= n; i ++)
#define foralp for(int i = 1; i <= 26; i ++)
using namespace std;
int n;
struct node{
	int a;
	char c;
}st[200005];
long long Sn,tmp,usu;
long long mid,maxn,maxi;
long long alp1[30],alp2[30];
void cmp_max(){
	foralp{
		if(maxn < alp1[i] + alp2[i]) maxi = i;
		maxn = max(maxn,alp1[i] + alp2[i]);
	}
}
signed main(){
	Year2026 October thirtyone
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	fori cin >> st[i].a >> st[i].c;
	fori Sn += st[i].a;
	tmp = (Sn + 1)/2;
	usu = st[n].a;
	if(Sn % 2 == 1){
		fori {
			if(tmp > st[i].a)tmp -= st[i].a;
			else {
				st[i].a -= 1;
				mid = i - 1;
				break;
			}
		}
		form alp1[int(st[i].c) - 64] += st[i].a;
		for_m alp2[int(st[i].c) - 64] += st[i].a;
		cmp_max();
		cout << Sn - maxn + usu;
	}
	else{
		fori{
			if(tmp > st[i].a)tmp -= st[i].a;
			else {
				mid = i - 1;
				break;	
			}		
		}
		form alp1[int(st[i].c) - 64] += st[i].a;
		for_m alp2[int(st[i].c) - 64] += st[i].a;
		cmp_max();
		cout << Sn - maxn + usu;
	}
	return 0;
} 
