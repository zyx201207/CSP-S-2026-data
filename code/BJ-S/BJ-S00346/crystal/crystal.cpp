#include<bits/stdc++.h>
using namespace std;
long long a[500010];
queue<long long>q;
int main(){
int n;
long long m;
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n;
cin>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n);
long long s=a[n-1];
int ma=1,l=1;
q.push(a[n-1]);
for(int i=n-2;i>=0;i--){
	q.push(a[i]);
	l+=1;
	s+=a[i];
	if(l*q.front()-s>m){
		q.pop();
		l--;
		s-=q.front();
	}
	ma=max(ma,l);
}
cout<<ma;
fclose(stdin);
fclose(stdout);
return 0;
}
