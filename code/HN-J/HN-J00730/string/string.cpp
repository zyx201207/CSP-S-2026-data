#include <iostream>
#include <cstdio>
using namespace std;
int number,a1,n[26],s,ns;
char c1;
int main()
{
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	cin>>number;
	for(int i=1;i<=number;i++)
	{
		cin>>a1>>c1;
		n[c1-'a']+=a1;
	}
	for(int i=0;i<26;i++)
	{
		if(n[i]>0) s++;
		ns+=n[i];
	}
	if(number==1 || s==1) cout<<"0"<<endl;
	else cout<<ns/2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
