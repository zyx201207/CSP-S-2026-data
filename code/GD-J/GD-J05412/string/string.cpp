#include<iostream>
//#include<algorithm>
using namespace std;
struct part{
	long long num;
	char ch;
}strs[200001];
//part str2[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>strs[i].num>>strs[i].ch;
	}
	long long l=1,r=strs[n-1].num,nl=0,nr=n-1;
	long long cnt=0;
	while(nl<nr)
	{
		if(strs[nl].num==strs[nr].num){
			if(strs[nl].ch!=strs[nr].ch)
			{
				cnt+=strs[nl].num;
			}
			nl+=1;
			nr-=1;
		}
		else{
			if(strs[nl].num<strs[nr].num){
				if(strs[nl].ch!=strs[nr].ch)
				{
					cnt+=strs[nl].num;
				}
				strs[nr].num-=strs[nl].num;
				nl++;
		    }
			else{
				if(strs[nl].ch!=strs[nr].ch)
				{
					cnt+=strs[nr].num;
				}
				strs[nl].num-=strs[nr].num;
				nr--;
			}
		}
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
