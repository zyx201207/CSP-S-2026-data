//GZ-S00275 遵义市第一中学 钱晨逸 
#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
char b[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,m=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
	{
		for(int k=m+1;k<=a[i];k++)
		b[k]=c[i];
		m+=a[i];
	}
	if(m%2==1)
	for(int i=1;i<=m/2+1;i++){
	if(b[i]==b[m+1-i]){
	sum=sum;
}
	else 
	sum++;
}
	else
	for(int i=1;i<=m/2;i++)
	if(b[i]!=b[m+1-i])
	sum++;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
}

