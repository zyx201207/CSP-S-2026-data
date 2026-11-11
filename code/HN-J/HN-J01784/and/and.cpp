#include<bits/stdc++.h>
using namespace std;
int a[200020]={0};
int cf(int y)
{
    if(y==0){
    	return 1;
	}else{
		int zs=1;
		for(int i=1;i<=y;i++)
		{
			zs*=2;
		}
	} 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s[210];
	string b[210];
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i];
		int num=a[i];
		int s1=0;
		while(num>0)
		{
			s1++;
			if(num%2==0)
			{
				s[i][s1]='0';	
			}else{
				s[i][s1]='1';
			} 
			num/=2; 	
		}
		for(int j=1;j<=s1;j++){
			b[i][s1-j+1]=s[i][j];
		}
	}
	if(m==1)
	{
		sort(a,a+n+1);
		cout<<a[n];
	}else{
//		int maxx=0;
//		int h=0;
//		for(int i=1;i<=n-1;i++)
//		{
//			for(int j=i+1;j<=n;j++)
//			{
//				for(int z=1;z<=b[i].length();z++)
//				{
//					
//					if(b[i][z]==b[j][z])
//					   h+=cf(z-1);
//				}
//				if(maxx<h)
//				{
//					maxx=h;
//				}
//			}
//		}
//		cout<<maxx
cout<<a[n]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
