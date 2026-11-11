#include<bits/stdc++.h>
using namespace std;
struct st{
	char id;
	long long num;
} a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].num >> a[i].id;
	}
	long long l=1,r=n,ans=0;
	long long fl=a[l].num,fr=a[r].num;
	char cl=a[l].id,cr=a[r].id;
//	cout << l << " " << fl << " " << cl << "     " << r << " " << fr << " " << cr << endl;
	while(l<r){
		if(fl<fr){
			if(cl!=cr) ans+=fl;
			fr-=fl;
			l++;
			fl=a[l].num;
			cl=a[l].id;
		}
		if(fl==fr){
			if(cl!=cr) ans+=fl;
			l++;
			fl=a[l].num;
			cl=a[l].id;
			r--;
			fr=a[r].num;
			cr=a[r].id;
		}
		if(fl>fr){
			if(cl!=cr) ans+=fr;
			fl-=fr;
			r--;
			fr=a[r].num;
			cr=a[r].id;
		}
//		cout << l << " " << fl << " " << cl << "     " << r << " " << fr << " " << cr << endl;
	}
	cout << ans;
	return 0;
}
