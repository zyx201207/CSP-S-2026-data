#include<bits/stdc++.h>
using namespace std;
int n;
struct kk{
	long long num;
	char ap;
};
kk s[200002];
kk t[200002];
void rever(){
	for(int i=1;i<=n;i++){
		t[i].num=s[n-i+1].num;
		t[i].ap=s[n-i+1].ap;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].num>>s[i].ap;
	}
	rever();
	int temp,idt=1,ids=1;
	long long ans=0;
	while(idt<=n&&ids<=n){
		int minn;
		if(t[idt].num==s[ids].num)minn=t[idt].num;
		else minn=min(t[idt].num,s[ids].num);
		if(t[idt].ap!=s[ids].ap)ans+=minn;
		t[idt].num-=minn;
		s[ids].num-=minn;
		if(t[idt].num==0)idt++;
		if(s[ids].num==0)ids++;
	}
	cout<<ans/2;
}
