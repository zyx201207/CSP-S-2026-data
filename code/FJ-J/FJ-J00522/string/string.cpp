#include<bits/stdc++.h>
using namespace std;
long long int n,l,l1,s,a[200020][2];

char b[200020];
bool f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1][0]>>b[1];
	l+=a[1][0];
	a[1][1]=l;
	l1++;
	for(int i=2;i<=n;i++){
		long long int x;
		char y;
		cin>>x>>y;
		l+=x;
		if(y==b[l1-1]){
			a[l1-1][0]+=x;
			a[l1-1][1]=l;
		}else{
			b[l1]=y;
			a[l1][0]=x;
			a[l1][1]=l;
			l1++;
		}
	}
	long long int h=(l+1)/2,mid,gap1=0,gap=0,gap2=0,i,j,i1,j1;
	char x,y;
	for(int i=1;i<=l1;i++){
//		cout<<a[i][0]<<b[i]<<a[i][1]<<endl;
		if(a[i][1]>=h){
			mid=i;
			break;
		}
	}
	if(!l%2){
		i=h;
		j=h+1;
		x=b[mid];
		i1=mid;
		if(j>mid)y=b[mid+1],j1=mid+1;
		else y=b[mid],j1=mid;
	}else{
		i=h-1;
		j=h+1;
		if(i<=a[mid-1][1])x=b[mid-1],i1=mid-1;
		else x=b[mid],i1=mid;
		if(j>mid)y=b[mid+1],j1=mid+1;
		else y=b[mid],j1=mid;
	}
	cout<<i<<x<<" "<<j<<y<<" "<<l;
	while(i>0 && j<=l ){
		if(i1-1>0)gap1=i-a[i1-1][1];
		else gap1=a[1][0]-gap;
		if(mid==1 && !l%2)gap1--;
		if(j1+1<=l1)gap2=a[j1][1]-j;
		else gap2=a[l1][0]-gap;
		if(mid==l1+1 && !l%2)gap1--;
		gap=0;
		cout<<a[i1-1][1]<<i<<endl;
		cout<<gap1<<" "<<gap2<<endl;
		if(gap1==gap2){
			if(b[j1]!=b[i1])s+=gap1;	
			i1--;
			j1++;
		}else if(gap1<gap2){
			if(b[j1]!=b[i1])s+=gap1;
			gap=gap2-gap1;
			i1--;
		}if(gap1>gap2){
			if(b[j1]!=b[i1])s+=gap2;
			gap=gap1-gap2;
			j1++;
		}
		i-=gap1;
		j+=gap2;
	}
	cout<<s;
	return 0;
}