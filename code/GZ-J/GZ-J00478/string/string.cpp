//GZ-J00478 遵义航天高级中学 张煜皓
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+4;
long long n,ans;
struct s{
	int number;
	char ch;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].number>>a[i].ch;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].ch!=a[r].ch){
			ans+=min(a[l].number,a[r].number);
		}
		if(a[l].number>a[r].number){
			a[l].number-=a[r].number;
			r--;
		}else if(a[l].number<a[r].number){
			a[r].number-=a[l].number;
			l++;
		}else{
			a[r].number=a[l].number=0;
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
