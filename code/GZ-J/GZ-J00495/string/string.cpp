//GZ-J00495 六盘水知见外国语学校 蔡昕清
#include<bits/stdc++.h>
using namespace std;
char m[10000000000];
int main(){
	int a,b=0,count=0,d;
	cin>>a;
	for(int i=0;i<a;i++){
		d=0;
		cin>>d;
		char q;
		cin>>q;
		for (int j=b;j<b+d;j++){
			m[j]=q;;
		}
		b+=d;
	}
	int j=b-1;
	if (b/2==0) b/=2;
	if (b/2!=0) b=b/2+1;
	for(int i=0;i<b-1;i++){
		if (m[i]!=m[j]) count++;
		j--;
	}
	cout<<count;
	return 0;
}
