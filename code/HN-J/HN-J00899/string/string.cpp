#include <iostream>


int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for (int i = 1 ,i>=0,i++)
	{
		n[i]=n[i]+n[i+1];
		if (i > 0){
			cout << "2";
		}
	}
	freclose("string.in",stdin);
	freclose("string.out",stdout);
	return 0;
}
