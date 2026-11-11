#include<bits/stdc++.h>
using namespace std;
long long n[200005];
char c[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,all=0,change = 0;
	cin >> a;
	for(int i = 0;i<a;i++) {
		cin>>n[i]>>c[i];
	}
	int head=0,tail=a-1,index=0;//新建两个指针 
	while(head<tail) {
		//index++;
		if(c[head] == c[tail]) {//当两个字符相等时，直接pop掉
			long long minus = min(n[head],n[tail]);
			n[head]-=minus;
			n[tail]-=minus;
			if(n[head]==0)head++;//如果当前指针的剩余字符数量为0：换到下一个char 
			if(n[tail]==0)tail--;
		}
		else {//当两个字符不同的时候，change加较少字符的哪一个，较少字符的那个移到下一位 
			long long num = min(n[head],n[tail]);
			//cout<<"第"<<index<<"次循环，changes加了"<<num<<endl;
			change+=num;
			n[head]-=num;
			n[tail]-=num;
			if(n[head]==0)head++;//与if中的同理 
			if(n[tail]==0)tail--;
		}
	}
	cout << change;
	return 0;
}
