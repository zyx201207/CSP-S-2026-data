#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+9;
int c,n,m,d,q;
int w[MAXN],t[MAXN][100],a[MAXN][100];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++){
		int l,r,sum=0;
		cin>>l>>r;
		for(int j=l;j<=r;j++) sum+=w[i];
		cout<<sum<<endl;
	}
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