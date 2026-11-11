#include <iostream> 
using namespace std;
int main()
{
	int a,n,j,result=0;
	char x;
	string r,f;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a>>x;
		for (int j=0;j<a;j++){
			r+=x;		
		}
	}
	j=r.size()-1;
	for (int i=0;i<r.size();i++){
		f+=r[j];
		j-=1;
	}

	for (int i=0;i<r.size();i++){
		if (r[i]!=f[i])result++;
	}
	result/=2;
	cout<<result;
	return 0;
}
