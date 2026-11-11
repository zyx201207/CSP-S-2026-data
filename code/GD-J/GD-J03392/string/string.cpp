//TLE
#include <bits/stdc++.h>

using namespace std;

int n;
int cin_temp1;
char cin_temp2;
string right,left;
string llong="";

int main(){
	freopen("string.in","r",stdin);//Ò»¶¨È¥×¢ÊÍ£¡ 
	freopen("string.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cin_temp1>>cin_temp2;
		for(int j=0;j<cin_temp1;j++)
			llong+=cin_temp2;
	}
	long long difference=0;
	for(size_t i=0,j=llong.size()-1;i<=j;i++,j--)
		if(llong[i]!=llong[j]){
			difference++;
		}
	cout<<difference;
	return 0;
}
