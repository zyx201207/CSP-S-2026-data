#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],x;
long long s;
char ch[200005],ch1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>ch1;
		if(ch1==ch[n])a[n]+=x;
		else ch[++n]=ch1,a[n]=x;
	}
	for(int i=1,j=n;i<=j;){
		if(a[i]>a[j]){
			a[i]=a[i]-a[j];
			if(ch[i]!=ch[j])
			s+=a[j];
			j--;
		} 
		else if(a[i]<a[j]){
			a[j]=a[j]-a[i];
			if(ch[i]!=ch[j])
			s+=a[i];
			i++;
		}
		else {
			if(ch[i]!=ch[j])
			s+=a[i];
			i++;j--;
		}
	}
	cout<<s;

	return 0;
}
/*
10
3 a
2 b
3 a
2 b
3 a
2 b
3 a
2 b
3 a
2 b
*/
