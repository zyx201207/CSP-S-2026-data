#include<bits/stdc++.h>
using namespace std;
struct str{
	int a;
	char c;
};
int main(){
	ifstream ifs("string.in");
	ofstream ofs("string.out");
	int n;
	str st[200100];
	ifs>>n;
	for(int i=0;i<n;i++){
		ifs>>st[i].a>>st[i].c;
	}
	long long l=0,r=n-1,cnt=0;
	while(l<r){
		char c1=st[l].c,c2=st[r].c;
		int a1=st[l].a,a2=st[r].a;
		int tmp=min(a1,a2);
		if(c1!=c2){
			cnt+=tmp;
		}
		st[l].a-=tmp;st[r].a-=tmp;
		if(st[l].a==0) l++;
		if(st[r].a==0) r--;
	}
	ofs<<cnt;
	return 0;
}
