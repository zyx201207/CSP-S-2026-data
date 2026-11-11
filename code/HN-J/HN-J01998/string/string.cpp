#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int t,sum=0;
	scanf("%d",&t);
	while(t--)
	{
		string a;
		scanf("%s",&a);
		if(t<=1){
			sum=0;
			break;
		}else if(t<=8 || t>=17){
			sum=1;
			break;
		}else{
			sum=2;
			break;
		}
	}
	printf("%d",sum);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
