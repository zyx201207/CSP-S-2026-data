#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<char> a;

struct stu{
	int id,cnt;
}num[1000010];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int sum = 0;
	for(int i = 0;i<n;i++){
		char x;
		cin>>x;
		a.push_back(x);
	}
	for(int i = 1;i<=m;i++){
		num[i].id = i;
		num[i].cnt = 0;
	}
	while(sum!=n){
		string t = "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   ";
		for(int i = sum;i<n;i++){
			int x = a[i];
			if((int)(t.find(x)) <= n and (int)(t.find(x)) != i){
				for(int j = (int)(t.find(x));j<n;j++) t[i] = ' ';
			}
			t[t.find(' ')] = x;
		}
		for(int i = 1;i<=m;i++){
			if(t.find(i) <= n){
				num[i].cnt += 1;
			}
		}
		sum++;
	}
	for(int i = 1;i<=m;i++){
		cout<<num[i].cnt<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
