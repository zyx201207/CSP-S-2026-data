#include<iostream> 
#include<string>
using namespace std;
string s="",tmp2;
int main()
{
	freopen("string.in",'r',fopen) ;
	freopen("string.out",'w',fopen);
	int n,l=0,tmp,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp>>tmp2;
		for(int j=0;j<tmp;j++) s+=tmp2;
		l+=tmp;
	}
	int left=0,right=l-1;
	while(right>left)
	{
		if(s[left]!=s[right]) ans++;
		left++;
		right--;
	}
	cout<<ans;
}
