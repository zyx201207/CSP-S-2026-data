#include <iostream>
#include <vector>

int n,m;

std::vector<int>a;

std::vector<int>b;

int ans;

void dfs(int now,int xuan) {
	if(xuan==m) {
		int sum=b[0];
		for(auto x:b)
			sum&=x;

		ans=std::max(ans,sum);
		return;
	}

	if(now>=n+1)
		return;

	{
		b.push_back(a[now]);
		dfs(now+1,xuan+1);
		b.pop_back();
	}
	{
		dfs(now+1,xuan);
	}
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	scanf("%d%d",&n,&m);

	a.resize(n);

	for(auto&x:a)scanf("%d",&x);

	if(n<=20)
		dfs(0,0);
	else if(n<=2000 and m==1)
		for(auto x:a)ans=std::max(ans,x);
	else if(n<=2000 and m==n) {
		ans=a[0];
		for(auto x:a)ans&=x;
	} else if(n<=2000 and m==2)
		for(int i=0; i<(int)a.size(); ++i)
			for(int j=i+1; j<(int)a.size(); ++j)
				ans=std::max(a[i]&a[j],ans);
	else {
		bool flag=true;
		for(auto x:a) {
			if(x>=4) {
				flag=false;
				break;
			}
		}

		if(flag) {
			int three=0;
			for(auto x:a)
				if(x==3)
					three++;
			if(three>=m)
				return printf("3\n"),0;


			int two=0;
			for(auto x:a)
				if(x==2)
					two++;
			if(two>=m)
				return printf("2\n"),0;


			int one=0;
			for(auto x:a)
				if(x==1)
					one++;
			if(three+one>=m)
				return printf("1\n"),0;
			else
				return puts("0"),0;
		}
	}

	printf("%d\n",ans);
	return 0;
}
/*
Input:
4 2
3 15 12 12
Input:
5 3
31 3 1 15 7
Input
21 1
1 2 3 4 5 6 7 8 9 10 11 10 9 8 7 6 5 4 3 2 1


PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/
