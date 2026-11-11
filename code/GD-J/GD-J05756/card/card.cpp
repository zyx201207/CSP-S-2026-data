#include<bits/stdc++.h>
using namespace std;
struct S{
	int num,cishu;
}s3[100000];
int main(){
	fopen("card.in","r",stdin);
	fopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b;
	cin>>a>>b;
	int s[1000000];
	for(int i = 1;i<=a;i++)
	{
		cin>>s[i];
		s3[i].num = s[i];
	}
	int s1[100000]={};
	int s2[100000]={};
	for(int i =1;i<=b;i++){
		int pos = 1;
		int pos1 = 1;
		while(s[a] == 0){
			s1[pos] = s[pos];
			s[pos] = 0;
			for(int k = 1;k <= i-1;k ++){
				if(s1[i] == s1[k])
				{
					for(int z = k;z <= k;z++,pos1++){
						s2[pos1] = s1[z]; 
						s1[z] = 0;
					}
				}
			}
			pos++;
		}
		pos1++;
		for(int j = 1;j<=a;j++){
			if(s1[j]!=0){
				s[pos1] = s1[j];
			}
		}
		for(int j = 1;j <= a;j++){
			s[j] = s2[j];
			s2[j] = 0;
		}
		for(int j = 1;j<=a;j++)
		{
			for(int k = 1;k<=a;k++){
				if(s1[j] == s3[k].num){
					s3[k].cishu++;
				}
			} 
		}
	}
	for(int i = 1;i<=a;i++)
	{
		cout<<s3[i].cishu<<" ";
	}
	return 0;
} 
