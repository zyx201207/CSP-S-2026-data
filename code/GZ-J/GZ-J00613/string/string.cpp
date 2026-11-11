//GZ-J00613   胡震洋   遵义航天高级中学 
#include <bits/stdc++.h>
using namespace std;
struct box{
	int a;
	string c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	box m[n+5];
	for(int i=1;i<=n;i++){
		cin>>m[i].a>>m[i].c;
	}
	int min=INT_MAX;
	for(int i=1;i<=n;i++){
		if(m[i].a<min)min=m[i].a;
	}
	cout<<min;
	return 0;
}

