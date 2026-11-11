#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+9;
int n,m,a[MAXN],now,ans;
bool check(){
	int cc=a[2]-a[1];
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=cc) return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(check()&&n>5000){
		int kk=0,cc=a[2]-a[1];
		for(int i=1;i<=n;i++) if((0+(i-1)*cc)*i/2<=m) kk=i;
		cout<<kk;
		return 0;
	}
	sort(a+1,a+n+1);
	int r=1;
	while(r<=n){
		int l=r,sum=0,res=0;
		while(l>=1&&sum<=m){
			sum+=a[r]-a[l];
			res++;
			l--;
		}
		if(sum>m) ans=max(ans,res-1);
		else ans=max(ans,res);
		r++;
	}
	cout<<ans;
	return 0;
}//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
/*100 90
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100*/