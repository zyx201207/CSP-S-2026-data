#include <bits/stdc++.h>
using namespace std;
long long n,m,x,ans=0;
char y;
string l,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>x>>y;
	m+=x;
	while(x--)
	{
		l+=y;
	}
} 

for(int i=m-1;i>=m/2;i--){
	k+=l[i];
}
if(m%2==0){
for(int i=0;i<=m/2-1;i++){
	
	if(k[i]!=l[i])ans++;
}
}
else {
	for(int i=0;i<=m/2;i++){
		
	if(k[i]!=l[i])ans++;
}
}
cout<<ans;
return 0;
}

