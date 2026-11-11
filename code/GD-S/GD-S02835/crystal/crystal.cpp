#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
long long b[100000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
long long n,m;
long long ret=0;
scanf("%lld%lld",&n,&m);
for(int i=1;i<=n;i++)
{
	scanf("%lld",&a[i]);
}
if(n==1)
{
	printf("1");
	return 0;
}
else if(n==2)
{
	if(a[1]==a[2])
	{
		printf("2");
		return 0;
	}
	else
	{
		if(a[1]<a[2])
		{
			if(a[1]+m>=a[2])
			{
				printf("2");
				return 0;
			}
			else
			{
				printf("1");
				return 0;
			}
		}
		else
		{
			if(a[2]+m>=a[1])
			{
				printf("2");
				return 0;
			}
			else
			{
				printf("1");
				return 0;
			}
		}
	}
}
else if(n==3)
{
	if(a[1]==a[2]&&a[3]==a[2])
	{
		printf("3");
		return 0;
	}
	else if(a[1]==a[2]&&a[1]>=a[3])
	{
		if(a[3]+m>=a[1])
		{
			printf("3");
			return 0;
		}
	}
	else if(a[2]==a[3]&&a[2]>=a[1])
	{
		if(a[1]+m>=a[3])
		{
			printf("3");
			return 0;
		}
	}
	else if(a[1]==a[3]&&a[1]>=a[2])
	{
		if(a[2]+m>=a[1])
		{
			printf("3");
			return 0;
		}
	} 
	else if(a[1]>a[2]&&a[1]>a[3])
	{
		int cnt3=0;
	    int cnt1=a[1]-a[2];
	    int cnt2=a[1]-a[3];
	    if(a[2]>a[3])
	    {
	    	 cnt3=a[2]-a[3];
		}
		if(a[3]>a[2])
		{
			 cnt3=a[3]-a[2];
		}
	    if(m>=cnt1+cnt2)
	    {
	    	printf("3");
	    	return 0;
		}
		else if(m>=cnt1||m>=cnt2||m>=cnt3)
		{
			printf("2");
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
	else if(a[2]>a[1]&&a[2]>a[3])
	{
		int cnt3=0;
	    int cnt1=a[2]-a[1];
	    int cnt2=a[2]-a[3];
	    if(a[1]>a[3])
	    {
	    	 cnt3=a[1]-a[3];
		}
		if(a[3]>a[1])
		{
			 cnt3=a[3]-a[1];
		}
	    if(m>=cnt1+cnt2)
	    {
	    	printf("3");
	    	return 0;
		}
		else if(m>=cnt1||m>=cnt2||m>=cnt3)
		{
			printf("2");
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
		else if(a[3]>a[1]&&a[3]>a[2])
	{
		int cnt3=0;
	    int cnt1=a[3]-a[1];
	    int cnt2=a[3]-a[2];
	    if(a[2]>a[1])
	    {
	    	 cnt3=a[2]-a[1];
		}
		if(a[1]>a[2])
		{
			 cnt3=a[1]-a[2];
		}
	    if(m>=cnt1+cnt2)
	    {
	    	printf("3");
	    	return 0;
		}
		else if(m>=cnt1||m>=cnt2||m>=cnt3)
		{
			printf("2");
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
}
else if(n==4)
{
	if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4])
	{
		printf("4");
		return 0;
	}
	else if(a[1]==a[2]&&a[1]==a[3]&&a[1]>=a[4])
	{
		if(a[4]+m>=a[1])
		{
			printf("4");
			return 0;
		}
		else
		{
			printf("3");
			return 0;
		 } 
	}
		else if(a[1]==a[2]&&a[1]==a[4]&&a[1]>=a[3])
	{
		
		
		if(a[3]+m>=a[1])
		{
		
			printf("4");
			return 0;
		}
		else
		{
			printf("3");
			return 0;
		}
	}
		else if(a[1]==a[3]&&a[1]==a[4]&&a[1]>=a[2])
	{
		if(a[2]+m>=a[1])
		{
			printf("4");
			return 0;
			}
			else
			{
				printf("3");
				return 0;
			}
	}
		else if(a[4]==a[2]&&a[4]==a[3]&&a[4]>=a[1])
	{
		if(a[1]+m>=a[4])
		{
			printf("4");
			return 0;
		}
		else
		{
			printf("3");
			return 0;
		}
	}
	else if(a[1]==a[2]&&a[2]>a[3]&&a[2]>a[4])
	{
		 int cnt1=a[2]-a[3];
		 int cnt2=a[2]-a[4];
		 if(m>=cnt1+cnt2)
		 {
		 	printf("4");
		 	return 0;
		  } 
		  else if(m>=cnt1||m>=cnt2)
		  {
		  	printf("3");
		  	return 0;
		  }
		  else
		  {
		  	printf("2");
		  	return 0;
		  }
	}
		else if(a[1]==a[3]&&a[3]>a[2]&&a[3]>a[4])
	{
		 int cnt1=a[3]-a[2];
		 int cnt2=a[3]-a[4];
		 if(m>=cnt1+cnt2)
		 {
		 	printf("4");
		 	return 0;
		  } 
		  else if(m>=cnt1||m>=cnt2)
		  {
		  	printf("3");
		  	return 0;
		  }
		  else
		  {
		  	printf("2");
		  	return 0;
		  }
	}
		else if(a[1]==a[4]&&a[4]>a[2]&&a[4]>a[3])
	{
		 int cnt1=a[4]-a[2];
		 int cnt2=a[4]-a[3];
		 if(m>=cnt1+cnt2)
		 {
		 	printf("4");
		 	return 0;
		  } 
		  else if(m>=cnt1||m>=cnt2)
		  {
		  	printf("3");
		  	return 0;
		  }
		  else
		  {
		  	printf("2");
		  	return 0;
		  }
	}
			else if(a[2]==a[4]&&a[4]>a[1]&&a[4]>a[3])
	{
		 int cnt1=a[4]-a[1];
		 int cnt2=a[4]-a[3];
		 if(m>=cnt1+cnt2)
		 {
		 	printf("4");
		 	return 0;
		  } 
		  else if(m>=cnt1||m>=cnt2)
		  {
		  	printf("3");
		  	return 0;
		  }
		  else
		  {
		  	printf("2");
		  	return 0;
		  }
	}
		else if(a[2]==a[3]&&a[3]>a[1]&&a[3]>a[4])
	{
		 int cnt1=a[3]-a[1];
		 int cnt2=a[3]-a[4];
		 if(m>=cnt1+cnt2)
		 {
		 	printf("4");
		 	return 0;
		  } 
		  else if(m>=cnt1||m>=cnt2)
		  {
		  	printf("3");
		  	return 0;
		  }
		  else
		  {
		  	printf("2");
		  	return 0;
		  }
	}
	else if(a[4]==a[3]&&a[3]>a[1]&&a[3]>a[2])
	{
		 int cnt1=a[3]-a[1];
		 int cnt2=a[3]-a[2];
		 if(m>=cnt1+cnt2)
		 {
		 	printf("4");
		 	return 0;
		  } 
		  else if(m>=cnt1||m>=cnt2)
		  {
		  	printf("3");
		  	return 0;
		  }
		  else
		  {
		  	printf("2");
		  	return 0;
		  }
	}
	else if(a[1]>a[2]&&a[1]>a[3]&&a[1]>a[4])
	{
		int cnt1=a[1]-a[2];
		int cnt2=a[1]-a[3];
		int cnt3=a[1]-a[4];
		int cnt4=0;
		int cnt5=0;
		if(a[2]>a[3]&&a[2]>a[4])
		{
			cnt4=a[2]-a[3];
			cnt5=a[2]-a[4];
		}
		else if(a[3]>a[2]&&a[3]>a[4])
		{
			cnt4=a[3]-a[2];
			cnt5=a[3]-a[4];
		}
		else
		{
			cnt4=a[4]-a[2];
			cnt5=a[4]-a[3];
		}
	    if(m>=cnt1+cnt2+cnt3)
		{
			printf("4");
			return 0;
		}
		else if(m>=cnt1+cnt2||m>=cnt2+cnt3||m>=cnt1+cnt3)
		{
			printf("3");
			return 0;
		}
		else if(m>=cnt4+cnt5)
		{
			printf("3");
			return 0;
		}
		else if(m>=cnt1||m>=cnt2||m>=cnt3)
		{
			printf("2");
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
		else if(a[2]>a[1]&&a[2]>a[3]&&a[2]>a[4])
	{
		int cnt1=a[2]-a[1];
		int cnt2=a[2]-a[3];
		int cnt3=a[2]-a[4];
		int cnt4=0;
		int cnt5=0;
		if(a[1]>a[3]&&a[1]>a[4])
		{
			cnt4=a[1]-a[3];
			cnt5=a[1]-a[4];
		}
		else if(a[3]>a[1]&&a[3]>a[4])
		{
			cnt4=a[3]-a[1];
			cnt5=a[3]-a[4];
		}
		else
		{
			cnt4=a[4]-a[1];
			cnt5=a[4]-a[3];
		}
	    if(m>=cnt1+cnt2+cnt3)
		{
			printf("4");
			return 0;
		}
		else if(m>=cnt1+cnt2||m>=cnt2+cnt3||m>=cnt1+cnt3)
		{
			printf("3");
			return 0;
		}
		else if(m>=cnt4+cnt5)
		{
			printf("3");
			return 0;
		}
		else if(m>=cnt1||m>=cnt2||m>=cnt3)
		{
			printf("2");
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
	else if(a[3]>a[1]&&a[3]>a[2]&&a[3]>a[4])
	{
		int cnt1=a[3]-a[1];
		int cnt2=a[3]-a[2];
		int cnt3=a[3]-a[4];
		int cnt4=0;
		int cnt5=0;
		if(a[1]>a[2]&&a[1]>a[4])
		{
			cnt4=a[1]-a[2];
			cnt5=a[1]-a[4];
		}
		else if(a[2]>a[1]&&a[2]>a[4])
		{
			cnt4=a[2]-a[1];
			cnt5=a[2]-a[4];
		}
		else
		{
			cnt4=a[4]-a[1];
			cnt5=a[4]-a[2];
		}
	    if(m>=cnt1+cnt2+cnt3)
		{
			printf("4");
			return 0;
		}
		else if(m>=cnt1+cnt2||m>=cnt2+cnt3||m>=cnt1+cnt3)
		{
			printf("3");
			return 0;
		}
		else if(m>=cnt4+cnt5)
		{
			printf("3");
			return 0;
		}
		else if(m>=cnt1||m>=cnt2||m>=cnt3)
		{
			printf("2");
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
		else if(a[4]>a[1]&&a[4]>a[2]&&a[4]>a[3])
	{
		int cnt1=a[4]-a[1];
		int cnt2=a[4]-a[2];
		int cnt3=a[4]-a[3];
		int cnt4=0;
		int cnt5=0;
		if(a[1]>a[2]&&a[1]>a[3])
		{
			cnt4=a[1]-a[2];
			cnt5=a[1]-a[4];
		}
		else if(a[2]>a[1]&&a[2]>a[3])
		{
			cnt4=a[2]-a[1];
			cnt5=a[2]-a[3];
		}
		else
		{
			cnt4=a[3]-a[1];
			cnt5=a[3]-a[2];
		}
	    if(m>=cnt1+cnt2+cnt3)
		{
			printf("4");
			return 0;
		}
		else if(m>=cnt1+cnt2||m>=cnt2+cnt3||m>=cnt1+cnt3)
		{
			printf("3");
			return 0;
		}
		else if(m>=cnt4+cnt5)
		{
			printf("3");
			return 0;
		}
		else if(m>=cnt1||m>=cnt2||m>=cnt3)
		{
			printf("2");
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
}
else if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]==a[5])
{
	printf("5");
	return 0;
}
else if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4]&&a[4]>a[5])
{
	if(a[5]+m>=a[4])
	{
		printf("5");
		return 0;
	}
	else
	{
		printf("4");
		return 0;
	}
}
else if(a[1]==a[2]&&a[2]==a[3]&&a[3]==a[5]&&a[5]>a[4])
{
	if(a[4]+m>=a[5])
	{
		printf("5");
		return 0;
	}
	else
	{
		printf("4");
		return 0;
	}
}
else if(a[1]==a[2]&&a[2]==a[5]&&a[5]==a[4]&&a[4]>a[3])
{
	if(a[3]+m>=a[4])
	{
		printf("5");
		return 0;
	}
	else
	{
		printf("4");
		return 0;
	}
}
else if(a[1]==a[3]&&a[3]==a[5]&&a[5]==a[4]&&a[4]>a[2])
{
	if(a[2]+m>=a[4])
	{
		printf("5");
		return 0;
	}
	else
	{
		printf("4");
		return 0;
	}
}
else if(a[2]==a[3]&&a[3]==a[5]&&a[5]==a[4]&&a[4]>a[1])
{
	if(a[1]+m>=a[4])
	{
		printf("5");
		return 0;
	}
	else
	{
		printf("4");
		return 0;
	}
}
else if(a[1]==a[2]&&a[2]==a[3]&&a[3]>a[4]&&a[3]>a[5])
{
	int cnt1=a[1]-a[4];
	int cnt2=a[1]-a[5];
	if(m>=cnt1+cnt2)
	{
		printf("5");
		return 0;
	 } 
	 else if(m>=cnt1||m>=cnt2)
	 {
	 	printf("4");
	 	return 0;
	 }
	 else
	 {
	 	printf("3");
	 	return 0;
	 }
}
else if(a[1]==a[2]&&a[2]==a[4]&&a[4]>a[3]&&a[4]>a[5])
{
	int cnt1=a[1]-a[3];
	int cnt2=a[1]-a[5];
	if(m>=cnt1+cnt2)
	{
		printf("5");
		return 0;
	 } 
	 else if(m>=cnt1||m>=cnt2)
	 {
	 	printf("4");
	 	return 0;
	 }
	 else
	 {
	 	printf("3");
	 	return 0;
	 }
}
else if(a[1]==a[2]&&a[2]==a[5]&&a[5]>a[3]&&a[5]>a[4])
{
	int cnt1=a[1]-a[3];
	int cnt2=a[1]-a[4];
	if(m>=cnt1+cnt2)
	{
		printf("5");
		return 0;
	 } 
	 else if(m>=cnt1||m>=cnt2)
	 {
	 	printf("4");
	 	return 0;
	 }
	 else
	 {
	 	printf("3");
	 	return 0;
	 }
}
else if(a[1]==a[4]&&a[4]==a[5]&&a[5]>a[3]&&a[5]>a[2])
{
	int cnt1=a[1]-a[3];
	int cnt2=a[1]-a[2];
	if(m>=cnt1+cnt2)
	{
		printf("5");
		return 0;
	 } 
	 else if(m>=cnt1||m>=cnt2)
	 {
	 	printf("4");
	 	return 0;
	 }
	 else
	 {
	 	printf("3");
	 	return 0;
	 }
}
else if(a[2]==a[4]&&a[4]==a[5]&&a[5]>a[3]&&a[5]>a[1])
{
	int cnt1=a[2]-a[3];
	int cnt2=a[2]-a[1];
	if(m>=cnt1+cnt2)
	{
		printf("5");
		return 0;
	 } 
	 else if(m>=cnt1||m>=cnt2)
	 {
	 	printf("4");
	 	return 0;
	 }
	 else
	 {
	 	printf("3");
	 	return 0;
	 }
}
else if(a[2]==a[4]&&a[4]==a[3]&&a[3]>a[5]&&a[3]>a[1])
{
	int cnt1=a[2]-a[5];
	int cnt2=a[2]-a[1];
	if(m>=cnt1+cnt2)
	{
		printf("5");
		return 0;
	 } 
	 else if(m>=cnt1||m>=cnt2)
	 {
	 	printf("4");
	 	return 0;
	 }
	 else
	 {
	 	printf("3");
	 	return 0;
	 }
}
else if(a[1]==a[4]&&a[4]==a[3]&&a[3]>a[5]&&a[3]>a[2])
{
	int cnt1=a[1]-a[5];
	int cnt2=a[1]-a[2];
	if(m>=cnt1+cnt2)
	{
		printf("5");
		return 0;
	 } 
	 else if(m>=cnt1||m>=cnt2)
	 {
	 	printf("4");
	 	return 0;
	 }
	 else
	 {
	 	printf("3");
	 	return 0;
	 }
}
else if(a[3]==a[4]&&a[4]==a[5]&&a[5]>a[1]&&a[5]>a[2])
{
	int cnt1=a[3]-a[2];
	int cnt2=a[3]-a[1];
	if(m>=cnt1+cnt2)
	{
		printf("5");
		return 0;
	 } 
	 else if(m>=cnt1||m>=cnt2)
	 {
	 	printf("4");
	 	return 0;
	 }
	 else
	 {
	 	printf("3");
	 	return 0;
	 }
}
if(a[1]==a[2]&&a[2]>a[3]&&a[2]>a[4]&&a[2]>a[5])
{
	int cnt1=a[1]-a[3];
	int cnt2=a[1]-a[4];
	int cnt3=a[1]-a[5];
	int cnt4=0;
	int cnt5=0;
    if(a[3]>a[4]&&a[3]>a[5])
    {
    	cnt4=a[3]-a[4];
    	cnt5=a[3]-a[5];
	}
	else if(a[4]>a[3]&&a[4]>a[5])
	{
		cnt4=a[4]-a[3];
		cnt5=a[4]-a[5];
	}
	else
	{
		cnt4=a[5]-a[3];
		cnt5=a[5]-a[4];
	}
	if(m>=cnt1+cnt2+cnt3)
	{
		printf("5");
		return 0;
	}
	else if(m>=cnt1+cnt2||m>=cnt2+cnt3||m>=cnt1+cnt3)
	{
		printf("4");
		return 0;
	}
	else if(m>=cnt1||m>=cnt2||m>=cnt3||m>=cnt4+cnt5)
	{
		printf("3");
		return 0;
	}
	else
	{
		printf("2");
		return 0;
	}
}
if(a[1]==a[3]&&a[3]>a[2]&&a[3]>a[4]&&a[3]>a[5])
{
	int cnt1=a[1]-a[2];
	int cnt2=a[1]-a[4];
	int cnt3=a[1]-a[5];
	int cnt4=0;
	int cnt5=0;
    if(a[2]>a[4]&&a[3]>a[5])
    {
    	cnt4=a[2]-a[4];
    	cnt5=a[2]-a[5];
	}
	else if(a[4]>a[2]&&a[4]>a[5])
	{
		cnt4=a[4]-a[2];
		cnt5=a[4]-a[5];
	}
	else
	{
		cnt4=a[5]-a[2];
		cnt5=a[5]-a[4];
	}
	if(m>=cnt1+cnt2+cnt3)
	{
		printf("5");
		return 0;
	}
	else if(m>=cnt1+cnt2||m>=cnt2+cnt3||m>=cnt1+cnt3)
	{
		printf("4");
		return 0;
	}
	else if(m>=cnt1||m>=cnt2||m>=cnt3||m>=cnt4+cnt5)
	{
		printf("3");
		return 0;
	}
	else
	{
		printf("2");
		return 0;
	}
}
if(a[1]==a[4]&&a[4]>a[2]&&a[4]>a[3]&&a[4]>a[5])
{
	int cnt1=a[1]-a[2];
	int cnt2=a[1]-a[3];
	int cnt3=a[1]-a[5];
	int cnt4=0;
	int cnt5=0;
    if(a[2]>a[3]&&a[2]>a[5])
    {
    	cnt4=a[2]-a[3];
    	cnt5=a[2]-a[5];
	}
	else if(a[3]>a[2]&&a[3]>a[5])
	{
		cnt4=a[3]-a[2];
		cnt5=a[3]-a[5];
	}
	else
	{
		cnt4=a[5]-a[2];
		cnt5=a[5]-a[3];
	}
	if(m>=cnt1+cnt2+cnt3)
	{
		printf("5");
		return 0;
	}
	else if(m>=cnt1+cnt2||m>=cnt2+cnt3||m>=cnt1+cnt3)
	{
		printf("4");
		return 0;
	}
	else if(m>=cnt1||m>=cnt2||m>=cnt3||m>=cnt4+cnt5)
	{
		printf("3");
		return 0;
	}
	else
	{
		printf("2");
		return 0;
	}
}
if(a[1]==a[5]&&a[5]>a[2]&&a[5]>a[3]&&a[5]>a[4])
{
	int cnt1=a[1]-a[2];
	int cnt2=a[1]-a[3];
	int cnt3=a[1]-a[4];
	int cnt4=0;
	int cnt5=0;
    if(a[2]>a[3]&&a[2]>a[4])
    {
    	cnt4=a[2]-a[3];
    	cnt5=a[2]-a[4];
	}
	else if(a[3]>a[2]&&a[3]>a[4])
	{
		cnt4=a[3]-a[2];
		cnt5=a[3]-a[4];
	}
	else
	{
		cnt4=a[4]-a[2];
		cnt5=a[4]-a[3];
	}
	if(m>=cnt1+cnt2+cnt3)
	{
		printf("5");
		return 0;
	}
	else if(m>=cnt1+cnt2||m>=cnt2+cnt3||m>=cnt1+cnt3)
	{
		printf("4");
		return 0;
	}
	else if(m>=cnt1||m>=cnt2||m>=cnt3||m>=cnt4+cnt5)
	{
		printf("3");
		return 0;
	}
	else
	{
		printf("2");
		return 0;
	}
}
if(a[1]==a[5]&&a[5]>a[2]&&a[5]>a[3]&&a[5]>a[4])
{
	int cnt1=a[1]-a[2];
	int cnt2=a[1]-a[3];
	int cnt3=a[1]-a[4];
	int cnt4=0;
	int cnt5=0;
    if(a[2]>a[3]&&a[2]>a[4])
    {
    	cnt4=a[2]-a[3];
    	cnt5=a[2]-a[4];
	}
	else if(a[3]>a[2]&&a[3]>a[4])
	{
		cnt4=a[3]-a[2];
		cnt5=a[3]-a[4];
	}
	else
	{
		cnt4=a[4]-a[2];
		cnt5=a[4]-a[3];
	}
	if(m>=cnt1+cnt2+cnt3)
	{
		printf("5");
		return 0;
	}
	else if(m>=cnt1+cnt2||m>=cnt2+cnt3||m>=cnt1+cnt3)
	{
		printf("4");
		return 0;
	}
	else if(m>=cnt1||m>=cnt2||m>=cnt3||m>=cnt4+cnt5)
	{
		printf("3");
		return 0;
	}
	else
	{
		printf("2");
		return 0;
	}
}





for(int i=1;i<=1;i++)
{
	for(int j=i;j<=n;j++)
	{
		if(a[i]==a[j])
		{
			ret++;
		}
	}
}
if(n==ret)
{
	printf("%d",ret);
}

	return 0;
} 
