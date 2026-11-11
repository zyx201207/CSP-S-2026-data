//鲁卓然 贵阳市第18中学 GZ-J00236 
#include<bits/stdc++.h>
using namespace std;
int const N = 2e5+5;
int a[N];
int main()
{
 	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout); 
 	int n,m; cin>>n>>m;
 	for(int i = 1 ; i <= n ; i++) cin>>a[i];
 	if(m == 1)
 	{
 		int ans = -1;
 		for(int i = 1 ; i <= n ; i++) ans = max(ans,a[i]);
 		cout<<ans;
 		return 0;
	 }
	 if(m == 2)
	 {
	 	int ans = -1;
	 	for(int i = 1 ; i <= n ; i++)
	 	{
	 		for(int j = 1 ; j <= n ; j++)
	 		{
	 			if(i == j) continue;
	 			ans = max(ans,a[i]&a[j]);
			 }
		 }
		 cout<<ans;
		 return 0;
	 }
	 if(m == 3)
	 {
	 	int ans = -1;
	 	for(int i = 1 ; i <= n ; i++)
	 	{
	 		for(int j = 1 ; j <= n ; j++)
	 		{
	 			for(int m = 1 ; m <= n ; m++)
	 			{
	 				if(i == j || j == m || m == i) continue;
		 			ans = max(ans,(a[i]&a[j])&a[m]);
			   }

			 }
		 }
		 cout<<ans;
		 return 0;
	 }
	 if(m == 4)
	 {
	 	int ans = -1;
	 	for(int i = 1 ; i <= n ; i++)
	 	{
	 		for(int j = 1 ; j <= n ; j++)
	 		{
	 			for(int m = 1 ; m <= n ; m++)
	 			{
	 				for(int q = 1 ; q <= n ; q++)
	 				{
	 					if(i == j || j == m || m == q ||i == m || j == q) continue;
	 					 			ans = max(ans,a[i]&a[j]&a[m]&a[q]);
					 }
	 				
			   }

			 }
		 }
		 cout<<ans;
		 return 0;
	 }
	 if(m == 5)
	 {
	 	int ans = -1;
	 	for(int i = 1 ; i <= n ; i++)
	 	{
	 		for(int j = 1 ; j <= n ; j++)
	 		{
	 			for(int m = 1 ; m <= n ; m++)
	 			{
	 				for(int q = 1 ; q <= n ; q++)
	 				{
	 					for(int p = 1 ; p <= n ; p++)
	 					{
	 						
						 if(i == j || j == m || m == q ||i == m || j == q || i == p || j == p || m == p || q == p) continue;
	 					 			ans = max(ans,a[i]&a[j]&a[m]&a[q]&a[p]);}
					 }
	 				
			   }

			 }
		 }
		 cout<<ans;
		 return 0;
	 }
	return 0;
}
