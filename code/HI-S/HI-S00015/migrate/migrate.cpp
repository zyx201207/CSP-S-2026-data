#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n[2],m[2],a[m[2]],b[2],c[b[2]],F1,F2;
	cin>>n[2]>>m[2]>>a[m[2]]>>b[2]>>c[b[2]];
	for(int i=1;i<=m[2];i++){
	F1=a[i]+a[i+1];
	}
	for(int j=1;j<=b[2];j++){
	F1=a[j]+a[j+1];
	}
	if(F1<0)
		{
			F1*-1;
			if(F2<0)
			{
				F2*-1;
				if(F1<=0||F2<=0)
				{
					cout<<F1<<endl<<F2;
				}
}
}
	return 0;
}


