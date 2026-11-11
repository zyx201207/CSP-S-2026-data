#include <bits/stdc++.h>
using namespace std;
long long n, ans, x, cnt=1, k;
char ch;
struct {
	long long r, l, x;
	char ch;
}a[200001];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n, k=n;
	for(int i=1; i<=n; i++) {
		cin>>x>>ch;
		a[i]={cnt, cnt+x-1, x, ch}, cnt+=x;
	}
	cnt--;
	for(int i=1; (a[i].l<=(cnt+1)/2); i++) {
		if(cnt-a[i].l+1<=a[i].r) break;
		bool flag=1;
		while(flag){
			flag=0;
			if(cnt+1-a[i].l<a[k].r&&cnt+1-a[i].r<a[k].l&&cnt+1-a[i].l>=a[k].l){
				if(a[i].ch!=a[k].ch) ans+=(cnt+1-a[i].l)-a[k].l+1;
				k--, flag=1;
				//cout<<"1 "<<ans<<" ";
			}
			if(cnt+1-a[i].l<a[k].r&&cnt+1-a[i].r>a[k].l){
				if(a[i].ch!=a[k].ch) ans+=a[i].x;
			//	cout<<"2 "<<ans<<" ";
			}
			if(cnt+1-a[i].l>=a[k].r&&cnt+1-a[i].r<=a[k].l){
				//quan bao wei
				if(a[i].ch!=a[k].ch) ans+=a[k].x;
				k--, flag=1;
				//cout<<"3 "<<ans<<" ";
			}
			if((cnt+1-a[i].l>=a[k].r)&&(cnt+1-a[i].r>a[k].l)&&(cnt+1-a[i].r<a[k].r)){
				if(a[i].ch!=a[k].ch) ans+=a[k].r-(cnt+1-a[i].r)+1;
			//	cout<<"4 "<<ans<<" ";	
			}
			
		
		}
		
			
		//cout<<"\n";
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
