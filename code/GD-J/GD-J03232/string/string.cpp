#include<bits/stdc++.h> 
using namespace std ;
int a[10001] ;
string b[10001] ;
int main()
{
	//freopen("stringin","w",stdin) ;
	//freopen("stringout","r",stdout) ;
	int k = 0 ;
	int l ;
	cin >> l ;
	for(int i = 1 ; i <= l ; i ++)
	{
	 	cin >> a[i] >> b[i] ;
	}
	if(l % 2 == 0)
	{
		for(int i = 1 ; i <= l / 2 ; i ++)
		{
	 		if(b[i] == b[l])
	 		{
	 			if(a[i] > a[l])
	 			{	
					while(1 != 0)
	 				{
	 					if(a[i] > a[l])
	 					{
							a[i] = a[i] -a[l] ;
	 						l = l - 1 ;	
						}
						if(a[i] < a[l])
						{
							a[l] = a[l] - a[i] ;
							break ;
						}
					}
				}
				else
				{
					a[l] = a[l] - a[i] ;
				}
			}
			else
			{
				if(a[i] > a[l])
				{
					k = k + a[l] ;
					l = l - 1 ;
				}
				else
				{
					a[l] = a[l] - a[i] ;
				}
			}
		}
	}
	else
	{
		l = l + 1 ;
		k = k + 1 ;
		for(int i = 1 ; i <= l / 2 ; i ++)
		{
	 		if(b[i] == b[l])
	 		{
	 			if(a[i] > a[l])
	 			{	
					while(1 != 0)
	 				{
	 					if(a[i] > a[l])
	 					{
							a[i] = a[i] -a[l] ;
	 						l = l - 1 ;	
						}
						if(a[i] < a[l])
						{
							a[l] = a[l] - a[i] ;
							break ;
						}
					}
				}
				else
				{
					a[l] = a[l] - a[i] ;
				}
			}
			else
			{
				if(a[i] > a[l])
				{
					k = k + a[l] ;
					l = l - 1 ;
				}
				else
				{
					a[l] = a[l] - a[i] ;
				}
			}
		}
	}
	cout << k ;
	//fclose(stdin) ;
	//fclose(stdout) ;
	return 0 ;
}
