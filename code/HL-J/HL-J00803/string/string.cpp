#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}a[200005],i1[100005],i2[100005];
long long n,add,ans,q[3]={1,1,1},s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		add+=a[i].a;
	}
	add=add/2;
	long long add1=add;
	for(int i=1;i<=n/2;i++){
		if(add-a[i].a>=0){
		 i1[i]=a[i];
		 add-=a[i].a;
	    }
		else{
			i1[i].c=a[i].c;
			i1[i].a=add;
			s1=i;
			break;
		}
	}
	add=add1;
	for(int i=1;i<=n/2+1;i++){
		if(add1-a[n-i+1].a>=0){
		 i2[i]=a[n-i+1];
		 add1-=a[n-i+1].a;
	    }
		else{
			i2[i].c=a[n-i+1].c;
			i2[i].a=add1;
			s2=i;
			break;
		}
	}
	for(int i=1;i<=max(s1,s2);i++){
		if(i1[q[1]].c!=i2[q[2]].c){
			ans+=min(i1[q[1]].a,i2[q[2]].a);
			i1[q[1]].a-=min(i1[q[1]].a,i2[q[2]].a);
			i2[q[2]].a-=min(i1[q[1]].a,i2[q[2]].a);
			q[(i1[q[1]].a>i2[q[2]].a?2:1)]++;
		}
	}
	cout<<ans;
	return 0;
}