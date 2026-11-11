#include<bits/stdc++.h>

using namespace std;

long long arr[500005];
long long n,m;
long long total = 0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	sort(arr+1,arr+n+1);
	
	
	int k = n/2+1; 
	
	int i = k,j = k + 1;
	long long ci = arr[k] - arr[i];
	long long cj = arr[j] - arr[k];	
	while(i >= 1 && arr[i] == arr[k])
	{
		total += 1;
		i -= 1;
	}
	while(j <= n && arr[j] == arr[k])
	{
		total += 1;
		j += 1; 
	}
	
	
	while(i >= 1 && j <= n)
	{
		if(m <= 0) break;
		if(m < ci && m < cj) break; //都买不起了 直接break 防止死循环 
		
		if(arr[i] == arr[k])
		{
			total += 1;
			i -= 1;
		}
		if(arr[j] == arr[k]) 
		{
			total += 1;
			j += 1;
		}
		
		
		
		if(arr[i] != arr[k] && arr[j] != arr[k] && (m >= ci || m >= cj))
		{
			if(ci < cj && m >= ci)
			{
				m -= ci;
				total += 1;
				i -= 1;
				ci = arr[k] - arr[i];
			}
			else if(cj < ci && m >= cj)
			{
				m -= cj;
				total += 1;
				j += 1;
				cj = arr[j] - arr[k];
			}
			
			else if(ci == cj)
			{
				if(i >= 1 && m >= ci)
				{
					m -= ci;
					total += 1;
					i -= 1;
					ci = arr[k] - arr[i];
				}
				if(j <= n && m >= cj)
				{
					m -= cj;
					total += 1;
					j += 1;
					cj = arr[j] - arr[k];
				}
			}
		}
		
		else if(arr[i] != arr[k] && m >= ci && i >= 1)
		{
			m -= ci;
			total += 1;
			i -= 1;
			ci = arr[k] - arr[i];
		}
		else if(arr[j] != arr[k] && m >= cj && j <= n)
		{
			m -= cj;
			total += 1;
			j += 1;
			cj = arr[j] - arr[k];
		} 
	}	
	cout << total;
	return 0;	
} 
