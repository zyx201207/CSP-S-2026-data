#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
struct st{
	char c;
	int num;
};
st a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long lcnt,ans=0;
	bool flag=true;
	st t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].c;
		lcnt+=a[i].num;
	}
	t=a[0];
	int i=0,j=n-1;
	st tmp1,tmp2;
	while(i<n&&j>=0){
		tmp1=a[i];
		tmp2=a[j];
		if(flag){
			if(t.c!=tmp2.c) ans+=min(t.num,tmp2.num);
			if(t.num<tmp2.num){
				t.c=tmp2.c;
				flag=false;
				i++;
			}else{
				j--;
			}
			t.num=abs(tmp2.num-t.num);
		}else{
			if(t.c!=tmp1.c) ans+=min(t.num,tmp1.num);
			if(t.num<tmp1.num){
				t.c=tmp1.c;
				flag=true;
				j--;
			}else{
				i++;
			}
			t.num=abs(tmp1.num-t.num);
		}
	}
	cout<<ans/2;
	return 0;
}
