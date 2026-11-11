#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int gs;
	char zm;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&s[i].gs,&s[i].zm);
	}
	int i=1;
	while(i<n)
	{
		while(s[i].gs<=0) i++;
		while(s[n].gs<=0) n--; 
		if(s[i].zm!=s[n].zm) 
		{
			if(s[i].gs>s[n].gs)
			{ a+=s[n].gs; s[n].zm=s[i].zm;  }
			else 
			{ a+=s[i].gs; s[i].zm=s[n].zm;  }
		}
		if(s[i].gs>s[n].gs) { s[i].gs-=s[n].gs; n--; }
		else if(s[i].gs==s[n].gs)  { i++; n--;}
		else { s[n].gs-=s[i].gs; i++; }
	}
	printf("%d",a);
	fclose(stdin);fclose(stdout);
	return 0;
} 
