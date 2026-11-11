/*
 * card.cpp
 * 
 * Copyright 2026 noi linux <noilinux@ubuntu>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,p,u;
	cin>>n>>m;
        int c[10005],q[1005];
        for(int i=1;i<=n;i++){
	        cin>>c[i];
		}
		for(u=0;u<=n-1;u++){
			for(int y=0;y<=u;y++){
				if(c[u]=c[y]){
					for(p=0;p<=y;p++){
						q[p]=c[p];
					}
				}
				else{
					continue;
				}
			}
		}
	for(int j=0;j<=p-1;j++){
		cout<<q[j]<<" ";
	}
	cout<<n;
	return 0;
}

