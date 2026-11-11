//GZ-J00492 遵义市第十六中学 何世灏
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,b,p=0;
	long long a1[200005];
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		scanf("%d",&a1[i]);
	}sort(a1+1,a1+1+n);
	for(int i=1;i<=n;i++){
		int l=0;
		l=a1[i];
		for(int j=i+1;j<i+b;j++){
			l&=a1[j];
		}p=max(p,l);
	}
	cout<<p;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

