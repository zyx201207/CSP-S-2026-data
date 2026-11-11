#include<bits/stdc++.h>
using namespace std; 
struct st{
	char c;
	long long s,e,l;                 //s:第i段的开头, e:第i段的结尾 l:长度 
};
vector<st> vec;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		long long a;char c;        //输入 a c 
		cin>>a>>c;
		st k;
		k.c=c;
		k.s=len+1;           //第i段的s是原S长度+1 
		len+=a;
		k.e=len;
		k.l=a;
		vec.push_back(k);
	}
	long long sum=0,left=1,right=len;      //left right是检测是否回文的 
	long long stl=0,str=n-1;               //stl str代表第left right个字符所在段落 
	for(;left<right;){              //left>=right代表S已回文 
		if(left>vec[stl].e)stl++;      //如果第left个字符不在第stl段，则stl++ 
		if(right<vec[str].s)str--;
		if(vec[stl].c!=vec[str].c)sum++;//检测第left个字符是否等于第right个字符 
		left++;
		right--;
	}
	cout<<sum;
	return 0;
}
