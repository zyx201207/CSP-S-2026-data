#include<bits/stdc++.h>
using namespace std;
long long n,a[200009],l=1,r,ans;
char ch[200009];
bool check(){
	if(l>r)return 0;
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}r=n;
	while(check()){
//		cout<<a[l]<<" "<<a[r]<<" ";
		if(a[l]>=a[r]){
			if(ch[l]!=ch[r])ans+=a[r];
			a[l]-=a[r];
			r--;
			if(a[l]==0)l++;
		}else{
			if(ch[l]!=ch[r])ans+=a[l];
			a[r]-=a[l];
			l++;
			if(a[r]==0)r--;
		}
//		cout<<ans<<endl;
	}cout<<ans;
	return 0;
} /*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
