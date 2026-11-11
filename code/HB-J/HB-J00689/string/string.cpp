#include <bits/stdc++.h>
using namespace std;
int n;
long long co=0;
struct node{
	int num;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("stirng.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i].num,&a[i].c);
	}
	int r=n,l=1;
	int len1=a[l].num,len2=a[r].num;
	while(l<=n){
		if(a[l].c!=a[r].c)
		{
			co+=min(len1,len2);
		}
		if(len1<len2){
			l++;
			len2-=len1;
			len1=a[l].num;
		}
		else if(len1==len2){
			l++;
			r--;
			len1=a[l].num;
			len2=a[r].num;
		}
		else{
			r--;
			len1-=len2;
			len2=a[r].num;
		}
	}
	cout<<co/2;
	//9:31
	return 0;
}
