#include<bits/stdc++.h>
using namespace std;
long long l,a[200005],ans,id,num;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>l;
	int r=1;
	if(l==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=l;i++){
		cin>>a[i]>>b[i];
		num+=a[i];
	}
	if(num%2==0)num/=2;
	else num=num/2+1;
	for(int i=1;i<=l;i++){
		if(num<=a[i]){
			id=i;
			break;
		}
		else num-=a[i];
	}
	while(r!=id && l!=id){
		if(a[r]<a[l]){
			if(b[r]!=b[l])ans+=a[r];
			a[l]-=a[r];
			r++;
		}else if(a[l]<a[r]){
			if(b[r]!=b[l])ans+=a[l];
			a[r]-=a[l];
			l--;
		}else {
			if(b[r]!=b[l])ans+=a[l];
			l--;
			r++;
		}
	}
	if(l==id){
		if(b[r]!=b[l])ans+=a[r];
	}else if(b[l]!=b[r])ans+=a[l];
	cout<<ans;
	return 0;
}
